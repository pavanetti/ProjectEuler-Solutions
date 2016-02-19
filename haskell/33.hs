module ProjectEuler.Problem33 (answer33) where

import Data.Ratio

answer33 :: Integer
answer33 = denominator $ product twoDigitsCuriosFractions

twoDigitsCuriosFractions :: [Ratio Integer]
twoDigitsCuriosFractions =
    concatMap curiousFraction [(a,b,c) | a <- [1..9], b <- [1..9], c <- [1..9]]

type RepeatingDigitsFraction a = (a,a,a)
curiousFraction :: RepeatingDigitsFraction Integer -> [Ratio Integer]
curiousFraction (a, b, c)
    | ab % bc == a % c = [ab % bc | ab < bc]
    | ab % cb == a % c = [ab % cb | ab < cb]
    | ab % ac == b % c = [ab % ac | ab < ac]
    | ab % ca == b % c = [ab % ca | ab < ca]
    | otherwise = []
    where
        ab = 10 * a + b
        ac = 10 * a + c
        bc = 10 * b + c
        ca = 10 * c + a
        cb = 10 * c + b

main :: IO ()
main = print answer33
