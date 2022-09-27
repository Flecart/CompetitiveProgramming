use std::fs;

#[derive(Debug)]
enum PairValue {
    Integer(i32),
    Pair(Pair),
}

#[derive(Debug)]
struct Pair {
    left: Box<PairValue>,
    right: Box<PairValue>,
}

impl Pair {
    pub fn new(l: i32, r: i32) -> Pair {
        Pair {
            left: Box::new(PairValue::Integer(l)),
            right: Box::new(PairValue::Integer(r)),
        }
    }
    
    pub fn get_magnitude(&self) -> i32 {
        let mut result = 0;
        match self.left.as_ref() {
            PairValue::Integer(val) => result += 3 * (*val),
            PairValue::Pair(pair) => result += 3 * pair.get_magnitude(),
        }

        match self.right.as_ref() {
            PairValue::Integer(val) => result += 2 * (*val),
            PairValue::Pair(pair) => result += 2 * pair.get_magnitude(),
        }

        result
    }

    pub fn from_string(s: &str) -> Pair {
        // primo carattere è sempre [, quindi si può skippare.
        let mut curr_pair = Pair::new(0, 0);

        let mut curr_idx = 1;

        // TODO se questa diventa una funzione è più cairno da gestire, per ora copio incollo
        if s.chars().nth(curr_idx).unwrap() == '[' {
            curr_pair.left = Box::new(PairValue::Pair(Self::from_string(&s[curr_idx..])));
            curr_idx += Self::find_closing_bracket(&s[curr_idx..]) + 2; // virgola e carattere
        } else {
            curr_pair.left = Box::new(PairValue::Integer(
                s.chars().nth(curr_idx).unwrap()
                .to_digit(10).unwrap() as i32));

            curr_idx += 2; // +2 per saltare la virgola 
        }

        if s.chars().nth(curr_idx).unwrap() == '[' {
            curr_pair.right = Box::new(PairValue::Pair(Self::from_string(&s[curr_idx..])));
        } else {
            curr_pair.right = Box::new(PairValue::Integer(
                s.chars().nth(curr_idx).unwrap()
                .to_digit(10).unwrap() as i32));
        }
        curr_pair
    }

    fn find_closing_bracket(s: &str) -> usize {
        let mut count = 0;
        for (i, c) in s.chars().enumerate() {
            if c == '[' {
                count += 1;
            } else if c == ']' {
                count -= 1;
            }
            if count == 0 {
                return i;
            }
        }
        0
    }

    pub fn add(first: Pair, second: Pair) -> Pair{
        let mut happened = true;
        let mut result = Pair {
            left: Box::new(PairValue::Pair(first)),
            right: Box::new(PairValue::Pair(second)),
        };

        while happened {
            happened = false;
            let (has_exploded, _, _) = result.explode(1);
            happened |= has_exploded;
            if happened {
                continue;
            }

            happened |= result.splits();
        }
        result
    }

    pub fn print(&self) {
        print!("[");
        match self.left.as_ref() {
            PairValue::Integer(i) => print!("{}", i),
            PairValue::Pair(p) => p.print(),
        }

        print!(",");

        match self.right.as_ref() {
            PairValue::Integer(i) => print!("{}", i),
            PairValue::Pair(p) => p.print(),
        }

        print!("]");
    }

    fn explode(&mut self, depth: i32) -> (bool, i32, i32) {
        let mut has_exploded;
        let mut left;
        let mut right;

//        println!("Explode at depth {depth}");
//        self.print();
//        println!("");

        if depth >= 4 {
            match *self.left {
                PairValue::Integer(_) => (),
                PairValue::Pair(ref mut p) => {
                    (has_exploded, left, right) = p.explode_if_possible();
                    if has_exploded {
                        self.left = Box::new(PairValue::Integer(0));
                        Self::add_to_box_first(&mut self.right, right);
                        right = 0;
                        return (has_exploded, left, right);
                    }
                }
            }
            
            match *self.right {
                PairValue::Integer(_) => (),
                PairValue::Pair(ref mut p) => {
                    (has_exploded, left, right) = p.explode_if_possible();
                    if has_exploded {
                        self.right = Box::new(PairValue::Integer(0));
                        Self::add_to_box_last(&mut self.left, left);
                        left = 0;
                        return (has_exploded, left, right);
                    }
                }
            }
        }

        match *self.left {
            PairValue::Integer(_) => (),
            PairValue::Pair(ref mut p) => {
                (has_exploded, left, right) = p.explode(depth + 1);
                if has_exploded {
                    if right != 0 {
                        Self::add_to_box_first(&mut self.right, right);
                        right = 0;
                    }
                    return (has_exploded, left, right);
                }
            }
        }

        match *self.right {
            PairValue::Integer(_) => (),
            PairValue::Pair(ref mut p) => {
                (has_exploded, left, right) = p.explode(depth + 1);
                if has_exploded {
                    if left != 0 {
                        Self::add_to_box_last(&mut self.left, left);
                        left = 0;
                    }
                    return (has_exploded, left, right);
                }
            }
        }

        (false, 0, 0)
    }

    fn add_to_box_last(box_val: &mut Box<PairValue>, val: i32) {
        match **box_val {
            PairValue::Integer(i) => {
                **box_val = PairValue::Integer(i + val);
            },
            PairValue::Pair(ref mut p) => {
                p.add_to_last(val);
            }
        }
    }

    fn add_to_box_first(box_val: &mut Box<PairValue>, val: i32) {
        match **box_val {
            PairValue::Integer(i) => {
                **box_val = PairValue::Integer(i + val);
            },
            PairValue::Pair(ref mut p) => {
                p.add_to_first(val);
            }
        }
    }

    fn add_to_last(&mut self, val: i32) {
        match *self.right {
            PairValue::Integer(ref mut i) => {
                *i += val;
            },
            PairValue::Pair(ref mut p) => {
                p.add_to_last(val);
            },
        }
    }

    fn add_to_first(&mut self, val: i32) {
        match *self.left {
            PairValue::Integer(ref mut i) => {
                *i += val;
            },
            PairValue::Pair(ref mut p) => {
                p.add_to_first(val);
            },
        }
    }

    fn explode_if_possible(&self) -> (bool, i32, i32) {
        let mut left_value = 0;
        let mut right_value = 0;

        let mut are_both_integers = true;
        match self.left.as_ref() {
            PairValue::Integer(val) => left_value = *val,
            PairValue::Pair(_) => are_both_integers = false
        }

        match self.right.as_ref() {
            PairValue::Integer(val) => right_value = *val,
            PairValue::Pair(_) => are_both_integers = false
        }

        if are_both_integers {
            return (true, left_value, right_value);
        } else {
            return (false, -1, -1);
        }
    }

    fn splits(&mut self) -> bool {
        match *self.left {
            PairValue::Integer(value) => {
                if value >= 10 {
                    self.left = Box::new(PairValue::Pair(Pair::new((value) / 2, (value + 1) / 2)));
                    return true;
                }
            },
            PairValue::Pair(ref mut p) => {
                let val = p.splits();
                if val {
                    return true;
                }
                // self.left = Box::new(PairValue::Pair(p));
            }
        }

        match *self.right {
            PairValue::Integer(value) => {
                if value >= 10 {
                    self.right = Box::new(PairValue::Pair(Pair::new((value) / 2, (value + 1) / 2)));
                    return true;
                }
            },
            PairValue::Pair(ref mut p) => {
                let val = p.splits();
                if val {
                    return true;
                }
            }
        }
        false
    } 
}

fn main() {
    let file_path = "input.txt";
    println!("In file {}", file_path);

    let contents = fs::read_to_string(file_path)
        .expect("Should have been able to read the file");

    let lines: Vec<_> = contents.split("\n").collect();

    let mut accumulator: Option<Pair> = None;

    for line in &lines {
        if line.len() < 5 {
            continue;
        }
        let pair = Pair::from_string(line);
//        println!("{:?}", pair);

        match accumulator {
            Some(acc) => {
//                println!("Summing the values");
                accumulator = Some(Pair::add(acc, pair));
            },
            None => {
                accumulator = Some(pair);
            }
        }
    }
    println!("Risultato è {}", accumulator.as_ref().unwrap().get_magnitude());
    
    let mut max_value = 0;
    
    for i in 0..lines.len() {
        for j in (i+1)..lines.len() {
            if lines[j].len() < 5 {
                continue;
            }
            let first_pair = Pair::from_string(lines[i]);
            let second_pair = Pair::from_string(lines[j]);
            let sum = Pair::add(first_pair, second_pair).get_magnitude();
            let sfirst_pair = Pair::from_string(lines[i]);
            let ssecond_pair = Pair::from_string(lines[j]);
            let other_sum = Pair::add(ssecond_pair, sfirst_pair).get_magnitude();
            if sum > max_value {
                max_value = sum;
            }
            if other_sum > max_value {
                max_value = other_sum;
            }
        }
    }
    println!("Max value is {}", max_value);
}
