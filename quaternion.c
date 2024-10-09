#include <stdio.h>
typedef struct {
    float s; // scalar part
    float v[3]; // vector part (i, j, k)
} Quaternion;

// Function to create a quaternion
Quaternion quat(float s, float i, float j, float k) {
    Quaternion q;
    q.s = s;
    q.v[0] = i;
    q.v[1] = j;
    q.v[2] = k;
    return q;
}

// Function to compute the complement (conjugate) of a quaternion
Quaternion complement_quat(Quaternion q) {
    Quaternion q_bar;
    q_bar.s = q.s;
    q_bar.v[0] = -q.v[0];
    q_bar.v[1] = -q.v[1];
    q_bar.v[2] = -q.v[2];
    return q_bar;
}

// Function to multiply two quaternions
Quaternion mult_quat(Quaternion q1, Quaternion q2) {
    Quaternion result;
    result.s = q1.s * q2.s - q1.v[0] * q2.v[0] - q1.v[1] * q2.v[1] - q1.v[2] * q2.v[2];
    result.v[0] = q1.s * q2.v[0] + q2.s * q1.v[0] + q1.v[1] * q2.v[2] - q1.v[2] * q2.v[1];
    result.v[1] = q1.s * q2.v[1] + q2.s * q1.v[1] + q1.v[2] * q2.v[0] - q1.v[0] * q2.v[2];
    result.v[2] = q1.s * q2.v[2] + q2.s * q1.v[2] + q1.v[0] * q2.v[1] - q1.v[1] * q2.v[0];
    return result;
}

// Function to compute the dot product of two quaternions
float dot_quat(Quaternion q1, Quaternion q2) {
    return q1.s * q2.s + q1.v[0] * q2.v[0] + q1.v[1] * q2.v[1] + q1.v[2] * q2.v[2];
}

int main() {
    // Example usage based on the problem statement
    Quaternion q = quat(0,0,0,1);
    Quaternion q_bar = complement_quat(q);
    
    Quaternion a = mult_quat(q, q_bar);
    float b = dot_quat(q, q_bar);
    
    // Printing results
    printf("Quaternion a: [%f, (%f, %f, %f)]\n", a.s, a.v[0], a.v[1], a.v[2]);
    printf("Dot product b: %f\n", b);

    return 0;
}
