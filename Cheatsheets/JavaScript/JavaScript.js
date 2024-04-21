function changeExternal() {
    document.getElementById("external").innerHTML = "External";
}

/*
document.write("Hello world!");
window.alert("Hello world!");
console.log("Hello world!");
*/

// Careful with document.write() - it can overwrite the entire document content!

let favouriteNumber = 10;
const e = 2.718;
let myName = "Kamil";

console.log(favouriteNumber + e);
console.log('My name is ' + myName);

// const is misleading - it defines a constant REFERENCE, not a VALUE (it has a meaning when it comes to e.g. arrays and objects)

let str = "";
let num = 0;
let big = BigInt("9999999999999999999999999");
let bool = true;
let undef = undefined;
let n = null;
let sym = Symbol();
let objObj = { name: "Kamil", age: 21 };
let objArr = [ "Kamil", 21 ];
let objDate = new Date("2002-05-04");

let unknown;
console.log(typeof(unknown));

function toCelsius(fahrenheit) {
    return (5 / 9) * (fahrenheit - 32);
}

console.log(toCelsius(80));

const me = {
    name: "Kamil",
    surname: "Kochanczyk",
    fullName: function() {
        return this.name + " " + this.surname;
    }
};

console.log(me.name);
console.log(me["surname"]);
console.log(me.fullName());

function displayDate() {
    let buttonID = "displayDate";
    let paragraphID = "currentDate";

    if (document.getElementById(buttonID).innerHTML === "Display date") {
        document.getElementById(buttonID).innerHTML = "Hide date";
        document.getElementById(paragraphID).innerHTML = Date();
    }
    else {
        document.getElementById(buttonID).innerHTML = "Display date";
        document.getElementById(paragraphID).innerHTML = "";
    }
}

let stringTemplate = `I am ${me.fullName()}`;
console.log(stringTemplate);

let nan = NaN;
let inf = Infinity;
let bigInt1 = BigInt("0");
let bigInt2 = 0n;

const favouriteNumbers = [10, 8, 5, 520, 69, 42];
favouriteNumbers.push(3, 2, 1, 7);
favouriteNumbers.pop();
favouriteNumbersLength = favouriteNumbers.length;

for (let i = 0; i < favouriteNumbersLength; i++) {
    console.log(favouriteNumbers[i]);
}

console.log(Math.random());

const now = new Date();

if (now.getHours() < 10) {
    console.log("Good morning");
}
else if (now.getHours() < 20) {
    console.log("Good day");
}
else {
    console.log("Good evening");
}

switch (now.getMonth()) {
    case 11:
    case 0:
    case 1:
        console.log("Winter");
        break;
    case 2:
    case 3:
    case 4:
        console.log("Spring");
        break;
    case 5:
    case 6:
    case 7:
        console.log("Summer");
        break;
    case 8:
    case 9:
    case 10:
        console.log("Autumn");
        break;
    default:
        console.log("Something's wrong");
        break;
}

for (let i = 0; i < 10; i++) {
    console.log(i);
}

const analogies = {
    html: "skeleton",
    css: "skin",
    js: "brain"
};

// for in -> object properties
for (let x in analogies) {
    console.log(analogies[x]);
}

let text = "Text";

// for of -> iterable objects
for (let x of text) {
    console.log(x);
}

i = 5;
while (i >= 0) {
    console.log(i * (-1));
    i--;
}

do {
    console.log("Ho, ho, ho!");
    i--;
} while (i >= 0);

for (let i = 0; i <= 10; i++) {
    if (i % 2 != 0) {
        continue;
    }

    if (i === 10) {
        break;
    }

    console.log(i);
}

// Unary + operator - converts a variable to a number
let x = "5";
let y = +x;
console.log(typeof(y));

let z = "five";
console.log(+z);

let regex = /w3schools/i;

function checkInput() {
    let input = document.getElementById("input").value;
    let message = "";

    try {
        if (input.trim() === "") throw "empty";
        if (isNaN(input)) throw "not a number";
        input = Number(input);
        if (input < 5) throw "too low";
        if (input > 10) throw "too high";
    }
    catch (err) {
        message += "Wrong input: " + err + " ---> ";
    }
    finally {
        message += input;
        document.getElementById("showResult").innerHTML = message;
    }
}

arrowFunction = () => {
    console.log("I am an arrow function");
}

arrowFunction();

lambda = (a, b) => a + " " + b;

console.log(lambda(0, 1));

class PieceOfArt {
    constructor(title) {
        this._title = title;
    }

    get title() {
        return this._title;
    }

    set title(x) {
        this._title = x;
    }
}

class Book extends PieceOfArt {
    constructor(title, totalPages, readPages) {
        super(title);
        this._totalPages = totalPages;
        this._readPages = readPages;
    }

    pagesLeft() {
        return this._totalPages - this._readPages;
    }

    read(pages) {
        this._readPages += pages;
    }

    static show(x) {
        console.log("Title: " + x.title);
    }
}

const book = new Book("Book", 300, 150);
console.log(book.pagesLeft());
book.read(50);
console.log(book.pagesLeft());
book.title = "Title";
console.log(book.title);
Book.show(book);