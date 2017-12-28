toNum:: String -> Maybe Int
toNum s = case reads s of
            [(n,"")] -> Just n
            _        -> Nothing

addOp :: Int -> Int -> Maybe Int
addOp a b = Just (a+b)
subOp :: Int -> Int -> Maybe Int
subOp a b = Just (a-b)
mulOp :: Int -> Int -> Maybe Int
mulOp a b = Just (a*b)
divOp :: Int -> Int -> Maybe Int 
divOp _ 0 = Nothing
divOp a b = Just (a `div` b)

toBinOp :: String -> Maybe (Int -> Int -> Maybe Int)
toBinOp "+" = Just addOp
toBinOp "-" = Just subOp
toBinOp "*" = Just mulOp
toBinOp "/" = Just divOp
toBinOp  _  = Nothing

eval :: String -> Maybe Int
eval expr =do 
    let [sa,sop,sb] = words expr
    a  <- toNum sa
    op <- toBinOp sop
    b  <- toNum sb
    a `op` b

main :: IO()
main = getLine >>= putStrLn . maybe "invalid" show . eval
