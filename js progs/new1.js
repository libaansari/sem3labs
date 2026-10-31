/*class student {
    constructor (name, age){
        this.name = name;
        this.age = age;
    }
    introduce () {
        return `my name is ${this.name} and i am ${this.age}years old`;
    }
    }
}
    */

class Student {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }

    introduce() {
        return `My name is ${this.name} and I am ${this.age} years old.`;
    }
}

    const student1 = new Student("Liba", 19);

console.log(student1.name);
console.log(student1.age);
console.log(student1.introduce());
