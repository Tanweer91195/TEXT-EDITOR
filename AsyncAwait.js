console.log("HArsh");

const delay = ()=>{
  setTimeout(()=>{
    console.log("H");
  },4000)

}

delay();

console.log("manoor");

// -----------------------------------

// Async await

const disp = async ()=>{
    await console.log("HArsh");
  
  const delay = ()=>{
    setTimeout(()=>{
      console.log("H");
    },4000)
  
  }
  
  await delay();
  
  await console.log("manoor");
};

disp();

