//jshint esversion: 9
function main(anotherFunction = () => {}) {
    function newFunction() {
        const callback = anotherFunction;
        if (this.count && this.count <= 3) callback();
        this.count = this.count + 1;
    }
    return newFunction.bind({ count: 0 });
}

const t = main(() => {
    console.log("absfe");
});

// t cannot be called more than 3 times

t();
t();
t();
t();
