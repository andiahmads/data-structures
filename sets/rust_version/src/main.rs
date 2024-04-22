use std::collections::HashMap;

struct Set {
    integer_map: HashMap<i32, bool>,
}

impl Set {
    fn new() -> Set {
        Set {
            integer_map: HashMap::new(),
        }
    }

    fn add_element(&mut self, element: i32) {
        if !self.contains_element(element) {
            self.integer_map.insert(element, true);
        }
    }

    fn contains_element(&self, element: i32) -> bool {
        self.integer_map.contains_key(&element)
    }

    fn intersect(&self, another_set: &Set) -> Set {
        let mut intersection_set = Set::new();
        for (key, _) in &self.integer_map {
            if another_set.contains_element(*key) {
                intersection_set.add_element(*key);
            }
        }
        intersection_set
    }

    fn union(&self, another_set: &Set) -> Set {
        let mut union_set = Set::new();
        for (key, _) in &self.integer_map {
            union_set.add_element(*key);
        }

        for (key, _) in &another_set.integer_map {
            union_set.add_element(*key);
        }
        union_set
    }

    fn print_set(&self) {
        print!("{{");
        for key in self.integer_map.keys() {
            print!("{} ", key);
        }
        println!("}}");
    }
}

fn main() {
    let mut set = Set::new();
    let mut another_set = Set::new();

    set.add_element(1);
    set.add_element(2);

    println!("Initial set: ");
    set.print_set();

    println!("Contains element 1: {}", set.contains_element(1));

    another_set.add_element(2);
    another_set.add_element(4);
    another_set.add_element(5);

    println!("Another set: ");
    another_set.print_set();

    println!("intersection of sets: ");
    set.intersect(&another_set).print_set();

    println!("union of sets: ");
    set.union(&another_set).print_set();
}

