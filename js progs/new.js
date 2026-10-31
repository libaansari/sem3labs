//objects

const obj= { name : "Liba"};

const obj1= {
    xyz : true,
    xyz1: 45,
    hobbies : ["Eat", "sleep" , "code"],

action: function () 
{
    return `time for ${this.hobbies}`;
}
};
console.log(obj1.xyz)
console.log(obj1.action())