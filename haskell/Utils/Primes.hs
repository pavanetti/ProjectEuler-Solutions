module Utils.Primes (isPrime, primes) where

isPrime :: Integer -> Bool
isPrime n = n /= 1 && and [n `mod` d /= 0 | d <- primesLessThanSquareRoot n]
    where primesLessThanSquareRoot x = takeWhile (\p -> p*p <= x) primes

primes :: [Integer]
primes = 2: 3: 5: filter isPrime primeCandidates
    where primeCandidates = 7:11:13:17:19:23:29:31: map (+30) primeCandidates
