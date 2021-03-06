import Openssl

def main (args : List String) : IO UInt32 := do
  try
    Openssl.sayHello "world"
    pure 0
  catch e =>
    IO.eprintln <| "error: " ++ toString e -- avoid "uncaught exception: ..."
    pure 1

