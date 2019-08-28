#! /usr/bin/env python3
# -*- coding: utf-8
#
# @File:      gen_seed
# @Brief:     generate seed using output of libfuzzer
# @Created:   May/05/2019
# @Author:    Jiahao Cai
#

import re

# llvm.log
with open('llvm.log', 'rb') as f:
  raw_log_content = f.read()
  log_lines = raw_log_content.decode('utf-8', 'ignore').split('\n')
  log_lines = log_lines[:-1]

class Record:
  def __init__(self, cov, ft, start, end):
    self.cov = cov
    self.ft = ft
    self.start = start
    self.end = end
  def __str__(self):
    return f'{self.cov}, {self.ft}, {self.start}, {self.end}'

records = []
recorded_things = []

# #22	REDUCE cov: 17 ft: 21 corp: 3/3872b exec/s: 0 rss: 32Mb L: 3841/3841 MS: 4 ChangeByte-ChangeBinInt-ChangeBinInt-EraseBytes-
# #2500	NEW    cov: 91 ft: 220 corp: 48/6618b exec/s: 0 rss: 36Mb L: 297/2346 MS: 3 ChangeBinInt-ChangeBinInt-CopyPart-
i = 0
while i < len(log_lines):
  line = log_lines[i]
  comment = re.match(r'.*#.*NEW\s+cov: ([0-9]+) ft: ([0-9]+).*', line)
  if comment:
    cov = comment.group(1)
    ft = comment.group(2)
    if (cov, ft) in recorded_things:
      i += 1
      continue
    else:
      recorded_things.append((cov, ft))
    # print(i, cov, ft)
    cursor = i
    counter = 0
    this_range = []
    # find start
    while cursor > 0:
      if '$$$' in log_lines[cursor]:
        this_range.append(cursor)
        break
      cursor -= 1
    cursor = i
    while cursor > 0:
      if '$$$' in log_lines[cursor]:
        this_range.append(cursor)
        break
      cursor += 1
    if len(this_range) == 2:
      records.append(Record(cov, ft, this_range[0], this_range[1]))
      while 'exec/s' in log_lines[i]:
        i += 1
    i += 1
  else:
    i += 1


covs = [int(r.cov) for r in records]
print(f'libFuzzer generated seeds from coverage {min(covs)} to {max(covs)}')

testcases = []
raw_log_lines = []

i = 0
line_num = 0
while i < len(raw_log_content):
  line = bytearray()
  while i < len(raw_log_content) and raw_log_content[i] != ord('\n'):
    line.append(raw_log_content[i])
    i += 1
  raw_log_lines.append(line)
  i += 1


assert len(raw_log_lines) == len(log_lines), f'{len(raw_log_lines)}, {len(log_lines)}'


for record in records:
  content = bytearray()
  for i in range(record.start, record.end + 1):
    content += raw_log_lines[i]
  # print(raw_log_lines[record.start: record.end + 1])
  # print(f'cov: {record.cov}, start: {record.start}, end: {record.end}')  
  real_content = bytearray()
  i = 0
  while i < len(content):
    if content[i] == ord('#'):
      while i < len(content) and content[i] != ord('\n'):
        i += 1
    else:
      real_content.append(content[i])
      i += 1
  if b'$$$' in real_content:
    while b'$$$' in real_content:
      index = real_content.index(b'$')
      del real_content[index:index+3]
  while len(real_content) > 0 and (real_content[0] == ord('\r') or real_content[0] == ord('\t')):
    real_content = real_content[1:]
  while len(real_content) > 0 and (real_content[-1] == ord('\r') or real_content[-1] == ord('\t')):
    real_content = real_content[:-1]
  if len(real_content) > 0:
    with open(f'./seed/cov_{record.cov}-ft_{record.ft}.txt', 'wb') as f:
      f.write(real_content)
  # print(real_content)
  # exit(0)
  # print(real_content.decode('utf-8', 'ignore'))

# print(raw_log_lines[1245].decode('utf-8', 'ignore'))
# print(raw_log_lines[1245], log_lines[1245])
      
    
print("seed_gen_done")
