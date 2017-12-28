import Text.Printf

type Coord = (Double, Double)

data Config =Config { rotAt::Coord
                     ,theta:: Double
                     ,ofs::(Double,Double)
                    }

type CoordConverter = Coord -> Coord

trans::(Double,Double) -> CoordConverter
trans (dx,dy) = \(x,y) -> (x+dx,y+dy)

rotate::Double->CoordConverter
rotate t = \(x,y) -> (cos t * x - sin t * y, sin t * x + cos t * y)

transByConfig :: Config -> CoordConverter
transByConfig config = trans (ofs config)

rotateByConfig :: Config -> CoordConverter
rotateByConfig config = postTrans . rotate (theta config) . preTrans where 
    rotateAt = rotAt config
    preTrans = trans (rotate pi $ rotateAt)
    postTrans= trans rotateAt

convertByConfig:: Config -> CoordConverter
convertByConfig config = transByConfig config . rotateByConfig config

main ::IO()
main = do 
    let config = Config{ rotAt = (0.5,0.5), theta=pi/4, ofs = (-0.5,-0.5)}
    let unitRect = [(0,0),(0,1),(1,1),(1,0)]
    let convertedRect = map(convertByConfig config) unitRect
    mapM_ (uncurry $ printf "(%.6f,%.6f)\n") convertedRect