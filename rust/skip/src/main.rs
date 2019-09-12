use std::io::{self, BufReader};
use std::io::prelude::*;
use std::fs::File;
use std::env;

fn main() -> io::Result<()> {

    let args: Vec<String> = env::args().collect();

    if args.len() == 2 {
      let nskip: u64 = args[1]
        .parse()
        .expect("First argument needs to be a whole integer");
      let mut ncount: u64 = 0;
      let stdin = io::stdin();
      for line in stdin.lock().lines() {
          if ncount >= nskip {
            println!("{}", line.unwrap());
          } else {
            ncount += 1;
          } 
      }
    } else if args.len() == 3 {
      let nskip: u64 = args[1]
        .parse()
        .expect("First argument needs to be a whole integer");
      let mut ncount: u64 = 0;
      let f = File::open(&args[2])?;
      let f = BufReader::new(f);
      for line in f.lines() {
          if ncount >= nskip {
            println!("{}", line.unwrap());
          } else {
            ncount += 1;
          } 
      }
    } else {
      println!("Usage: {} N [File]", args[0]);
    }

    Ok(())
}
