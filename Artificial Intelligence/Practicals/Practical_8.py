import tensorflow as tf
import numpy as np

# Define the architecture of the neural network
model = tf.keras.Sequential([
    tf.keras.layers.Input(shape=(2,)),  # Input layer with 2 features
    # Hidden layer with 4 neurons and ReLU activation
    tf.keras.layers.Dense(4, activation='relu'),
    # Output layer with 1 neuron and sigmoid activation
    tf.keras.layers.Dense(1, activation='sigmoid')
])

# Compile the model
model.compile(optimizer='adam', loss='binary_crossentropy',
              metrics=['accuracy'])

# Generate some example data
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y = np.array([0, 1, 1, 0])

# Train the model
model.fit(X, y, epochs=1000)

# Make predictions
predictions = model.predict(X)
print("Predictions:")
print(predictions)
