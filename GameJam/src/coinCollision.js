function coinCollision(character, gameObject) {
    let bottomOfcharacter = character.position.y + character.height;
    let rightOfcharacter = character.position.x + character.width;
    let leftOfcharacter = character.position.x;
  
    //ctx.fillStyle = 'red';
   // ctx.fillRect(leftOfcharacter,  character.position.y, rightOfcharacter-leftOfcharacter, character.height);

    let topOfObject = gameObject.position.y;
    let leftSideOfObject = gameObject.position.x;
    let rightSideOfObject = gameObject.position.x + gameObject.width;
    let bottomOfObject = gameObject.position.y + gameObject.height;
  
    if (
      bottomOfcharacter >= topOfObject &&
      rightOfcharacter >= leftSideOfObject &&
      leftOfcharacter <= rightSideOfObject
    ) {
    gameObject.markedForDeletion = true;
    coinscol++;
   /* } else {
      return false;
      */
    }

}