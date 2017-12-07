app nil Ys Ys .

app _0 Ys _1 and
  _0 holds list X Xs and
  _1 holds list X Zs 
if
  app Xs Ys Zs .

nrev nil nil .

nrev _0 Zs and
  _0 holds list X Xs 
if
  nrev Xs Ys and
  app Ys _1 Zs and
  _1 lists X .

s 0 1 .

s 1 2 .

s 2 3 .

s 3 4 .

s 4 5 .

s 5 6 .

s 6 7 .

s 7 8 .

s 8 9 .

s 9 10 .

s 10 11 .

s 11 12 .

s 12 13 .

s 13 14 .

s 14 15 .

s 15 16 .

s 16 17 .

s 17 18 .

dup 0 X X .

dup N X R 
if
  s N1 N and
  app X X XX and
  dup N1 XX R .

goal _0 and
  _0 lists X Y 
if
  dup 18 _1 _2 and
  _1 lists a b c d and
  _2 holds list X _3 and
  _3 holds list Y _4 .

