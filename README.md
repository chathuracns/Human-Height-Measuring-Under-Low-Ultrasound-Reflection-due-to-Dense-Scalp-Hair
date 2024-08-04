# Human Height Measuring Under Low Ultrasound Reflection Due to Dense Scalp Hair

## Overview
This project focuses on developing a method to measure human height using ultrasound sensors under challenging conditions caused by dense scalp hair. Dense hair absorbs and weakly reflects acoustic energy, making it difficult to get accurate measurements. Our goal is to enhance detection accuracy by preprocessing the dataset, manually analyzing patterns, and implementing a K-means clustering algorithm.

## Key Objectives
* Preprocess the dataset of ultrasound reflections: Account for acoustic transmission losses and field alterations caused by scalp hair.
* Conduct a manual analysis: Identify patterns in the dataset due to its limited size.
* Implement a K-means clustering algorithm: Classify data clusters corresponding to reflections from hair.
* Enhance detection accuracy: Achieve a detection accuracy of 3 cm, even under conditions of extremely low ultrasound reflection.

## Project Details

### Problem Statement
Dense scalp hair poses significant challenges for ultrasound-based distance measurements due to its high absorption and weak reflection of acoustic energy. This results in weak signals received by the sensor, leading to issues such as:
* Inconsistent values: Significant variation in the time taken for sound waves to reflect and return to the sensor.
* Weak reflections: Low amplitude signals caused by high absorption of ultrasound waves by hair.


![Diagram of the system](https://github.com/chathuracns/Human-Height-Measuring-Under-Low-Ultrasound-Reflection-due-to-Dense-Scalp-Hair/blob/main/Inconsistent%20data.png)

### Methodology
#### Data Collection:
* The ultrasound sensor is positioned above the head, emitting 10ms long sound pulses.
* The sensor measures the time taken for the pulses to reflect off the head and return.
* Multiple measurements (hundreds) are collected to ensure data reliability and allow for pattern analysis.

#### Manual Analysis:
* Visualized the collected data to identify patterns and inconsistencies.
* Detected three distinct measurement clusters:
  * Expected Values: Clusters corresponding to the head, shoulder, and a nearby table.
  * Random Values: Outliers caused by sensor imperfections.
  * Sharp Measurement Lines: Maximum time values (1500 ns) indicating insufficient return signals.

#### Clustering Algorithm:
* Implemented a K-means clustering algorithm to classify the data into three clusters (K=3), corresponding to the observed patterns.
* Initially used random values for K-means, but found that making educated guesses for the initial cluster centers significantly improved performance.

### Implementation Steps
* Initialization: Initialized the K-means algorithm with K=3 clusters, using better guesses for initial cluster centers based on observed data ranges.
* Clustering: Ran the K-means algorithm to classify the data into relevant clusters.
* Optimization: Optimized the clustering process to reduce convergence time and enhance accuracy.

### Observations and Improvements
* Manual Clustering: Improved initial guesses for K-means significantly enhanced clustering performance.
* Detection Accuracy: Achieved an accuracy of approximately 2 cm by optimizing the initial means and reducing convergence time.
* Measurement Reliability: Enhanced consistency in measurements, even with varying head positioning.

## Results
* Accuracy: Achieved a detection accuracy of 3 cm, with potential to further improve to 1 cm through advanced machine learning techniques.
* Efficiency: Improved algorithm convergence time by using educated guesses for initial cluster centers.
* Consistency: Reliable measurements even under conditions of low ultrasound reflection due to dense scalp hair.

## Future Work
* Accuracy Enhancement: Aim to achieve 1 cm accuracy by leveraging advanced machine learning techniques for more precise data analysis.
* Algorithm Optimization: Further optimize the clustering algorithm for faster convergence and better initial value selection.
* Expanded Testing: Conduct more experiments in varied conditions to ensure robustness and generalizability of the method.

## Conclusion
This project successfully addresses the challenge of measuring human height using ultrasound under low reflection conditions caused by dense scalp hair. By preprocessing the dataset, manually analyzing patterns, and implementing a K-means clustering algorithm, we significantly improved detection accuracy. Future work will focus on refining this approach to achieve even higher precision and reliability in measurements.
