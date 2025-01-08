const btnCart = document.querySelector('#count-logo');
const cart = document.querySelector('.cart');
const btnClose = document.querySelector('#cart-close');

btnCart.addEventListener('click', () => {
    cart.classList.add('cart-active');
});

btnClose.addEventListener('click', () => {
    cart.classList.remove('cart-active');
});
document.addEventListener('DOMContentLoaded', loadfood);

function loadfood()
 {
    LoadContent();

}
function LoadContent() {
    //remove
    let btnremove = document.querySelectorAll('.cart-remove');
    btnremove.forEach((btn) => {
        btn.addEventListener('click', removeitem);
    });

//item change
let qtyelement = document.querySelectorAll('.cart-quantity');
qtyelement.forEach((input) => {
    input.addEventListener('change', changeqty);
});

//product cart
let btnadd = document.querySelectorAll('.add-cart');
btnadd.forEach((btn) => {
    btn.addEventListener('click', addcart);
});

updatetotal();
}
//remove item
function removeitem() {
    if (confirm('are you sure to remove')) {  //alert                            
      //after
        let title=this.parentElement.querySelector('.cart-food-title').innerHTML;
        itemlist=itemlist.filter(ele=>ele.title != title);
        this.parentElement.remove();
        LoadContent();

    }  //console.log('click');
}
//qty
function changeqty() {
    if (isNaN(this.value) || this.value < 1) {
        this.value = 1;
    }
    //updatetotal();
    LoadContent();
}
//for no repeate
let itemlist=[];

//add cart
function addcart() {
    let food = this.parentElement;
    let title = food.querySelector('.food-title').innerHTML;
    let price = food.querySelector('.price').innerHTML;
    let img = food.querySelector('.food-img').src;
    // console.log(title,price,img);

let newproducts={title, price, img}
//check
if(itemlist.find((ele)=>ele.title==newproducts.title))
{
    alert("ITS ALREADY ADDED");
    return;
}
else{
    itemlist.push(newproducts);
}

    let newproduct = createcart(title, price, img);
    //create a new div
    let element = document.createElement('div');
    element.innerHTML = newproduct;
    let cartitems = document.querySelector('.cart-content');

    cartitems.append(element);
    LoadContent();  //from load content

}



function createcart(title, price, img)        //${img}ist select an particular element
{
    return `<div class="cart-box">
                    <img src="${img}" class="cart-img">      
                    <div class="detail-box">
                        <div class="cart-food-title">${title}</div>
                        <div class="price-box">
                            <div class="cart-price">${price}</div>
                            <div class="cart-amt">${price}</div>
                        </div>
                    <input type="number" value="1" class="cart-quantity">

                </div>
                <ion-icon name="trash-outline" class="cart-remove"></ion-icon>
            </div>
 `;
}
function updatetotal()
{
    const cartitems=document.querySelectorAll('.cart-box');
    const totalamt=document.querySelector('.total-price');


    let total=0;


    cartitems.forEach(product=>{
    let priceElement=product.querySelector('.cart-price');
    let price=parseFloat(priceElement.innerHTML.replace("RS.",""));
    let qty=product.querySelector('.cart-quantity').value;
    total+=(price*qty);
    product.querySelector('.cart-amt').innerText="RS."+(price*qty);
    });
    totalamt.innerHTML="RS."+total;

//add product

const cartcounts=document.querySelector('#count');
let count=itemlist.length;
cartcounts.innerHTML=count;

if(count==0){
    cartcounts.style.display='none';
}
else
{
    cartcounts.style.display='block';
}
}
