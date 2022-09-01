# Tic-Tac-Toe-4Hr
Creating Tic-Tac-Toe in C++ within 4 hrs

I spent 4 hours on this challenge. Board does not currently update by the functions. Manually changing starting board in code allows win condition checks to correctly occur.

I had some ideas on where to go, so I made a basic outline and started coding. I spent most of my time planning for the AI's moves and I ran into a problem where the board would not update. I fixed several smaller problems along the way while trying to fix it. Eventually I determined that I would need to completely rewrite the player and bot board updating functions. I started working on a design for that when my 4 hours ended. My first idea was to move the 2d board array to main, and update it there so that no data gets lost in a copy. I looked into more effctively using pointers, because they would allow me to keep the 2d array in the T3Board class, and still be able to modify it, but wasn't able to figure out a solution that didn't require me rewriting half the code.

I should have made sure the board worked first before jumping into the AI program design. As it stands, game is unplayable.
