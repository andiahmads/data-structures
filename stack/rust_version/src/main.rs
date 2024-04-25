struct Element {
    element_value: i32,
}

impl Element {
    fn new(value: i32) -> Self {
        Element {
            element_value: value,
        }
    }
}

struct Stack {
    elements: Vec<Element>,
}

impl Stack {
    fn new() -> Self {
        Stack {
            elements: Vec::new(),
        }
    }

    fn push(&mut self, element: Element) {
        self.elements.push(element);
    }

    fn pop(&mut self) -> Option<Element> {
        self.elements.pop()
    }
}

fn main() {
    let mut stack = Stack::new();

    let element1 = Element::new(3);
    let element2 = Element::new(5);
    let element3 = Element::new(7);
    let element4 = Element::new(9);

    stack.push(element1);
    stack.push(element2);
    stack.push(element3);
    stack.push(element4);

    if let Some(element) = stack.pop() {
        println!("{}", element.element_value);
    }

    if let Some(element) = stack.pop() {
        println!("{}", element.element_value);
    }

    if let Some(element) = stack.pop() {
        println!("{}", element.element_value);
    }

    if let Some(element) = stack.pop() {
        println!("{}", element.element_value);
    }
}
