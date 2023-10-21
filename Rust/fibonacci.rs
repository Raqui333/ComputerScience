// The Fibonacci sequence is a sequence in which each number
// is the sum of the two preceding ones. Numbers that are part
// of the Fibonacci sequence are known as Fibonacci numbers, 
// commonly denoted Fₙ

fn fibonacci(last_number: &mut u128, current_number: &mut u128) {
    let tmp = *last_number + *current_number;
    *last_number = *current_number;
    *current_number = tmp;
}

fn main() {
    let until: u128 = 184;

    let mut last_number: u128 = 0;
    let mut current_number: u128 = 1;

    println!("{}\n{}", last_number, current_number);
    fibonacci(&mut last_number, &mut current_number);

    for _ in 0..until {
        println!("{}", current_number);
        fibonacci(&mut last_number, &mut current_number);
    }
}