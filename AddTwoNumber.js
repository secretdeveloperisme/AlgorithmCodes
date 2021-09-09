
//  Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
 var addTwoNumbers = function(l1, l2) {
  let a = [];
  while(l1 != null){
      a.unshift(l1.val);
      l1 = l1.next;
  }
  let b = [];
  while(l2 != null){
      b.unshift(l2.val);
      l2 = l2.next;
  }
  let resultNumber= BigInt(a.join("")) + BigInt(b.join(""));
  let resultArr =resultNumber.toString().split("");
  let root = null;
  resultArr.forEach(value=>{
     root = addElement(root,value);
  })
  return root;
};
function addElement(l,value){
  let l1 = new ListNode(value);
  l1.next = l;
  return l1;
}
function toListNode(arr){
  arr = arr.reverse();
  let root = null;
  arr.forEach(value=>{
     root = addElement(root,value);
  })
  return root;
}
(()=>{
  let l1 = toListNode([1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]);
  let l2 = toListNode([5,6,4]);
  console.log(addTwoNumbers(l1, l2));
})()