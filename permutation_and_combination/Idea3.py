#!/bin/python
#combinations('ABCD', 2)# --> AB AC AD BC BD CD
#combinations(range(4), 3)# --> 012 013 023 123
import itertools

for prod in itertools.product('ABC', 'ABC'):
     print(prod)
# --> AB AC AD BC BD CD
print("-------------")
for comb in itertools.combinations('ABCD', 2):
     print(comb)
print("-------------")
     # --> 012 013 023 123
for comb in itertools.combinations(range(4), 3):
     print(comb)
 #--> AA AB AC BB BC CC
print("-------------")
for comb in itertools.combinations_with_replacement('ABC', 2):
     print(comb)
print("-------------")
for comb in itertools.combinations('ABC', 2):
     print(comb)
