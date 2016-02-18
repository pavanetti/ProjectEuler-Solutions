module Utils.Diagonalize where

diagonalize :: [a] -> [b] -> [(a, b)]
diagonalize = diagonalizeWith (\a b -> (a, b))

diagonalizeWith :: (a -> b -> c) -> [a] -> [b] -> [c]
diagonalizeWith f xs ys = concat $ diagonals 0
    where
        n  = min (length xs) (length ys)
        n' = max (length xs) (length ys)
        lastDiagonal = 2 * (n' - 1)
        diagonals k
            | k > lastDiagonal = []
            | otherwise =
                [
                    let
                        x = (xs !! m)
                        y = ys !! (k - m)
                    in
                    f x y | m <- [0.. k], k < m + n', m < n
                ]: diagonals (k + 1)
