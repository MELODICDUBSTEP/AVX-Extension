import matplotlib.pyplot as plt
import numpy as np

# Generate data
x = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512]
y = [0.8, 0.778, 0.612, 0.541, 0.43, 0.423, 0.581, 0.575, 0.654, 0.540] 

# Plot the curve
plt.plot(x, y)

# Add labels and title
plt.xlabel('X-axis / 4096 * 256')
plt.ylabel('Y-axis')
plt.title('Task1 Acceleration rate-data size curve')

# Add legend using the specified font

plt.ylim(0, 1)

# Show the plot
plt.savefig('curve2.png')