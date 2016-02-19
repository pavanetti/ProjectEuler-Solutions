module ProjectEuler.Problem37 (answer37) where

import Utils.Primes

answer37 :: Integer
answer37 = sum $ take 11 specialPrimes

truncateRight :: Integer -> Integer
truncateRight number = number `quot` 10

truncateLeft :: Integer -> Integer
truncateLeft number = let _10Exp = last $ takeWhile (< number) $ map (10^) [1..]
                      in number `mod` _10Exp

specialPrimes :: [Integer]
specialPrimes = filter isTruncablePrime $ drop 4 primes
    where
        isTruncablePrime number =
            isLeftTruncablePrime number && isRightTruncablePrime number
        isLeftTruncablePrime number
            | number < 10 = isPrime number
            | otherwise =
            let truncated = truncateLeft number
            in isPrime truncated && isLeftTruncablePrime truncated
        isRightTruncablePrime number
            | number < 10 = isPrime number
            | otherwise =
            let truncated = truncateRight number
            in isPrime truncated && isRightTruncablePrime truncated
