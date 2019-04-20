# -*- coding: utf-8 -*-
"""
Created on Sat Apr 20 19:07:16 2019

@author: Albert Ratajczak

Task:
    Write an alghoritm that merges point into an object (group of points), 
    if the distance from the point to any point in the object is lower than
    given value.
"""

import numpy as np
import matplotlib.pyplot as plt


class My_Object:
    def __init__(self, starting_point):
        """ stores all points of the object """
        self.points = np.array([starting_point])
        
    def merge(self, points, delta=1):
        """
        Merges all points (from array of points) to the object, if the distance 
        from the point to the object is lower than delta.
        :return: array of the points, which were not merged with the object
        """
        """ check each point in object """
        for sp in self.points:
            """ from group of points select the closest point to given point of
                the object """
            distances = np.array([np.linalg.norm(p-sp) for p in points])
            i = np.argmin(distances)
            print(sp, points[i], distances[i])
            """ if point is closer to the object than delta 
                - add it to the object """
            if distances[i] <= delta:
                self.points = np.append(self.points, [points[i]], axis=0)
                left_points = np.delete(points, i, axis=0)
                """ if there are points left - recursion """
                if left_points.size:
                    left_points = self.merge(left_points, delta)
                return left_points
        return points
    
    def x(self):
        return self.points[:,0]
    
    def y(self):
        return self.points[:,1]

# end of My_Object 
    

if __name__ == '__main__':
    """ random points in 2D """
    points_1 = np.random.randint(1, 5, (25, 2))
    points_2 = np.random.randint(15, 20, (25, 2))
    points = np.concatenate((points_1, points_2), axis=0)
    
    obj = []                        # array with objects
    obj_count = 0                   # counting objects
    while points.size:
        """ new object """
        obj_count += 1
        obj.append(My_Object(points[0]))             
        """ if there are points left - merge them in an object """
        if points[1:].size:                          
            points = obj[obj_count-1].merge(points[1:], 1.42)
        else:
            break
        
    for i in range(obj_count):
        print('\nObject {}'.format(i+1))
        print(obj[i].points)
        plt.plot(obj[i].x(), obj[i].y(), 's')

    plt.show()

# eof