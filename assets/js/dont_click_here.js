function showConfirm() {
    let result = confirm("Are you sure?");
    
    if (result) {
      showConfirm2()
    }
    
    else {
      denied()
    }
}

function showConfirm2() {
    let result = confirm("Are you really sure?");
    
    if (result) {
      showConfirm3()
    }
    
    else {
      denied()
    }
}

function showConfirm3() {
    alert("Haha, i just wasted your time!")
}

function denied() {
    alert("I knew, you are not sure!")
}
