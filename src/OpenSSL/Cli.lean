import OpenSSL

open OpenSSL

def main (args : List String) : IO UInt32 := do
  try
    let ctx ← Context.init ()
    let ssl ← ctx.initSSL
    pure 0
  catch e =>
    IO.eprintln <| "error: " ++ toString e
    pure 1
