module Utils.Digits where

digitsBase :: Integral i => i -> i -> [i]
digitsBase _ 0 = []
digitsBase base number = remainder: digitsBase base quotient
    where (quotient, remainder) = number `quotRem` base


digits :: Integral i => i -> [i]
digits = digitsBase 10
