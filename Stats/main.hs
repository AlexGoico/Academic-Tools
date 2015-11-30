binomial :: (Integral a) => a -> a -> a
binomial n k
  | n == 0 || k == 0 || n == k = 1
  | otherwise = product [n, n-1..lval+1] `div` product [sval, sval-1..1]
  where sval = min k (n-k)
        lval = max k (n-k)

permCount :: (Integral a) => a -> a -> Bool -> a
permCount n k True  
  | n < 0   = error "Must have positive values in combinatorics."
  | k < 0   = error "Permutation selections must be a positive number"
  | k > n   = error "Cannot pick more selections than the number of "
                    "elements in the set of selections."
  | n >= k  = product [n, n-1..n-k+1]
permCount n k False 
  | n < 0 = error "Must have positive values in combinatorics."
  | k < 0 = error "Permutation selections must be a positive number."
  | otherwise = n^k

combCount :: (Integral a) => a -> a -> Bool -> a
combCount n k True
  | n < 0 = error "Must have positive values in combinatorics."
  | k < 0 = error "Combination selections must be a positive number."
  | n == 0 = error "Combination with repetion cannot have value = 0."
  | otherwise = binomial (n+k-1) k
combCount n k False
  | n < 0 = error "Must have positive values in combinatorics."
  | k < 0 = error "Combination selections must be a positive number."
  | otherwise = binomial n k

main :: IO ()
main = return ()
