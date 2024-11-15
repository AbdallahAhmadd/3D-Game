//
//  DrawBall.hpp
//  Assignment2
//
//  Created by NANNA on 13/11/2024.
//

#ifndef DrawBall_hpp
#define DrawBall_hpp
#include <vector>
#include "DrawPlayer.hpp"
#include "Vector3f.hpp"
void drawBasketball();


struct Ball {
    Vector3f position;
    float rotationAngle;  // New attribute for individual rotation
};
// Declare a global vector to store the balls
extern std::vector<Ball> balls;



#endif /* DrawBall_hpp */
