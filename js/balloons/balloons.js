/*** Albert Ratajczak *** 2018-07-07 *******************************************
********************************************************************************
**** Simple game - by clicking a balloon you are shooting it. ******************
**** Red balloons add points and green reduce your lifes in the game. **********
*******************************************************************************/

// calling the function in window.onload to make sure the HTML is loaded
window.onload = function() {
	var balloon = [];		// arrays with all balloons on the sky
	var bottom;				// position of a balloon
	var i, j;				// for loops and other indexing
	var cStyle, bColor;		// for getting collor of a balloon
	var points = 0;			
	var gameLevel = 1;
	var lives = 3;
	
	var sky = document.getElementById('sky');
	var timebar = document.getElementById('timebar');
	var pointsDisplay = document.getElementById('points');
	var levelDisplay = document.getElementById('level');
	var livesDisplay = document.getElementById('lives');
    
	var gameTime = 120000;		// time of the game (ms)
	var leftTime = gameTime;	// left time of the game
	var timeNow = 0;			// current time of the game
	var nextBalloon = 10;		// time interval between balloons
	var deltaT = 10;			// refreshment time
    var deltaY = 1;				// number of px balloons are moving in each time step (speed)
	
	var t = setInterval(moveBalloons, deltaT);	// moving up the balloon
	var cdt = setInterval(countdown, deltaT);	// tine bar showing left time of the game
	

	function moveBalloons() {
		timeNow += deltaT; 
		if(timeNow==nextBalloon) {							// new balloon
			balloon.push(document.createElement('div'));		// new div element
			i = balloon.length - 1;
			balloon[i].className = 'balloon'; 					// it is balloon
			balloon[i].style.backgroundColor = randomColor();	// random balloon color
			balloon[i].onclick = function(){shootBalloon(this)};// clicking balloon equals to destroying it
			balloon[i].style.left =								// random X-position of balloon
				Math.floor(Math.random() * 540) + 'px';			// sky width - balloon width = 540
			sky.appendChild(balloon[i]);						// now balloon is child of sky
			nextBalloon = timeNow + randomInterval(deltaY);		// next balloon will appear at...
		}
		for(i=0; i<balloon.length; i++) {
			bottom = 400 - balloon[i].offsetTop;
			if(bottom<460) {  // move balloon
				balloon[i].style.bottom = bottom + deltaY + 'px';
			}
			else {            // balloon reached the top of the sky - remove balloon
				sky.removeChild(balloon[i]);
				balloon.splice(0, 1);
			}
		}
	}
    
    
	function countdown() {
		if(leftTime>0) {                                                       // there is still time for the game
			leftTime -= deltaT;
			timebar.style.width = Math.floor(600 * leftTime / gameTime) + 'px';  // reducing the bar
		}
		else {                                // time over -> game over
			gameOver();
		}
	}
    
    
	function randomInterval(speed) {
		return 10 * (Math.round(Math.random() * 50) + Math.round(60 / speed));  // max 500 ms + time for baloons t move,
	}                                                                           // so they don't overlap
	
	
	function randomColor() {
		if(Math.random()<0.8) {	// about 20% of green balloons
			return 'red'
		}
		else {
			return 'limegreen'
		}
	}
	
	
	function shootBalloon(b) {
		bStyle = window.getComputedStyle(b, null);
		bColor = bStyle.getPropertyValue('background-color');	// geting balloon color
		sky.removeChild(b);										// removing balloon from the sky...
		j = balloon.indexOf(b);									
		balloon.splice(j, 1);									// ...and the array of all balloons
		if(bColor=='rgb(255, 0, 0)'){
			points++;											// if balloon is red add point
			pointsDisplay.innerHTML = 'Points: ' + points;
			if(points%10==0) {								// each 10 points:
				deltaY++;										// - speed of balloons up
				gameLevel++;									// - level up
				levelDisplay.innerHTML = 'Level ' + gameLevel;
			}
		}
		else {													// balloon is not red - reduce lives
			lives--;
			livesDisplay.innerHTML = 'Lives: ' + lives;			
			if(lives<=0) {									
				gameOver();										// no more life - game over
			}
		}
	}
	
	
	function gameOver() {
		for(i=0; i<balloon.length; i++) {
			sky.removeChild(balloon[i]);  // removing all balloons
		}
		balloon.splice(0, balloon.length);
		sky.innerHTML = '<br /><br />GAME OVER';
		clearInterval(t);
		clearInterval(cdt);
	}
	
	
};