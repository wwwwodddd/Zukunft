fn main() {
    proconio::input! {
      s: String,
      t: String,
    }
    if s == "AtCoder" && t == "Land" {
      println!("{}", "Yes");
    } else {
      println!("{}", "No");
    }
}