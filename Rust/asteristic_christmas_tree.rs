// app mean to be a high-level version of 
// ../Assembly/asteristic_chrisman_tree.asm

fn main() {
    let mut x: usize = 1;
    let mut y: usize = 6; // size in lines
    for _i in 0..y {
        println!("{}{}", " ".repeat(y), "*".repeat(x));
        x += 2;
        y -= 1;
    }
}