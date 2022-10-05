import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras import optimizers
import numpy as np
import matplotlib.pyplot as plt

# load data
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data()

# normalization
x_train = x_train.reshape((60000, 28*28)) / 255.0
x_test = x_test.reshape((10000, 28*28)) / 255.0

# building model

def model_build(layer, node, initializer, lr, epoch):
    model = tf.keras.models.Sequential()
    model.add(tf.keras.layers.Dense(node, activation = 'relu', 
                                    kernel_initializer=initializer, 
                                    input_shape=(28*28,)))
    for i in range(layer-2):
        node = node/2
        model.add(tf.keras.layers.Dense(node, activation = 'relu'))
    model.add(tf.keras.layers.Dense(10, activation='softmax'))
    model.summary()

    model.compile(optimizer=optimizers.SGD(learning_rate=lr),
              loss='sparse_categorical_crossentropy', 
              metrics=['accuracy'])
    history = model.fit(x_train, y_train, epochs=epoch, verbose=2, validation_split=0.2)
    test_loss, test_acc = model.evaluate(x_test, y_test)
    print('\ntest accuracy:', test_acc, '              test loss:', test_loss)
    return history

# plot accuracy and loss

def model_plot(modelname):
    plt.figure(figsize=(16, 6))
    plt.subplot(121)
    plt.plot(modelname.history['accuracy'])
    plt.plot(modelname.history['val_accuracy'])
    plt.title('accuracy')
    plt.xlabel('Epoch')
    plt.ylabel('Accuracy')
    plt.legend(['Train', 'Valid'], loc='upper left')

    plt.subplot(122)
    plt.plot(modelname.history['loss'])
    plt.plot(modelname.history['val_loss'])
    plt.title('loss')
    plt.xlabel('Epoch')
    plt.ylabel('Loss')
    plt.legend(['Train', 'Valid'], loc='upper left')
    plt.show()


####################################### initializer ###

zero = model_build(3, 64, 'zeros', 0.01, 20)
model_plot(zero)

orth = model_build(3, 64, 'orthogonal', 0.01, 20)
model_plot(orth)

randnorm = model_build(3, 64, 'random_normal', 0.01, 20)
model_plot(randnorm)

henorm = model_build(3, 64, 'he_normal', 0.01, 20)
model_plot(henorm)

####################################### nodes ###

node_32 = model_build(3, 32, 'he_normal', 0.01, 20)
model_plot(node_32)

node_64 = model_build(3, 64, 'he_normal', 0.01, 20)
model_plot(node_64)

node_128 = model_build(3, 128, 'he_normal', 0.01, 20)
model_plot(node_128)

node_256 = model_build(3, 256, 'he_normal', 0.01, 20)
model_plot(node_256)

node_512 = model_build(3, 512, 'he_normal', 0.01, 20)
model_plot(node_512)

####################################### layers ###

layer2_256 = model_build(2, 256, 'he_normal', 0.01, 50)
model_plot(layer2_256)

layer3_256 = model_build(3, 256, 'he_normal', 0.01, 50)
model_plot(layer3_256)

layer4_256 = model_build(4, 256, 'he_normal', 0.01, 50)
model_plot(layer4_256)

layer5_256 = model_build(5, 256, 'he_normal', 0.01, 50)
model_plot(layer5_256)

layer2_128 = model_build(2, 128, 'he_normal', 0.01, 50)
model_plot(layer2_128)

layer3_128 = model_build(3, 128, 'he_normal', 0.01, 50)
model_plot(layer3_128)

layer4_128 = model_build(4, 128, 'he_normal', 0.01, 50)
model_plot(layer4_128)

layer5_128 = model_build(5, 128, 'he_normal', 0.01, 50)
model_plot(layer5_128)

print('========== valid accuracy ==========')
print('2 layer 256 nodes:', max(layer2_256.history['val_accuracy']))
print('3 layer 256 nodes:', max(layer3_256.history['val_accuracy']))
print('4 layer 256 nodes:', max(layer4_256.history['val_accuracy']))
print('5 layer 256 nodes:', max(layer5_256.history['val_accuracy']))
print('2 layer 128 nodes:', max(layer2_128.history['val_accuracy']))
print('3 layer 128 nodes:', max(layer3_128.history['val_accuracy']))
print('4 layer 128 nodes:', max(layer4_128.history['val_accuracy']))
print('5 layer 128 nodes:', max(layer5_128.history['val_accuracy']))

####################################### learning rate ###

model1_1 = model_build(3, 128, 'he_normal', 0.1, 20)
model_plot(model1_1)

model1_2 = model_build(3, 128, 'he_normal', 0.01, 100)
model_plot(model1_2)

model1_3 = model_build(3, 128, 'he_normal', 0.005, 150)
model_plot(model1_3)

model1_4 = model_build(3, 128, 'he_normal', 0.001, 300)
model_plot(model1_4)

model2_1 = model_build(3, 256, 'he_normal', 0.1, 20)
model_plot(model2_1)

model2_2 = model_build(3, 256, 'he_normal', 0.01, 100)
model_plot(model2_2)

model2_3 = model_build(3, 256, 'he_normal', 0.005, 150)
model_plot(model2_3)

model2_4 = model_build(3, 256, 'he_normal', 0.001, 300)
model_plot(model2_4)

####################################### epochs ###

model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Dense(256, activation = 'relu', 
                                kernel_initializer='he_normal', 
                                input_shape=(28*28,)))
model.add(tf.keras.layers.Dense(128, activation = 'relu'))
model.add(tf.keras.layers.Dense(10, activation='softmax'))
model.summary()

model.compile(optimizer=optimizers.SGD(learning_rate=0.1),
          loss='sparse_categorical_crossentropy', 
          metrics=['accuracy'])
history = model.fit(x_train, y_train, epochs=50, verbose=2, validation_split=0.2)
test_loss, test_acc = model.evaluate(x_test, y_test)
print('\ntest accuracy:', test_acc)
print('test loss:', test_loss)
print('best epoch:', model1_1.history['val_accuracy'].index(max(model1_1.history['val_accuracy'])))

plt.figure(figsize=(16, 6))
plt.subplot(121)
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.title('accuracy')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.legend(['Train', 'Valid'], loc='upper left')

plt.subplot(122)
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('loss')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.legend(['Train', 'Valid'], loc='upper left')
plt.show()

####################################### final model ###

model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Dense(256, activation = 'relu', 
                                kernel_initializer='he_normal', 
                                input_shape=(28*28,)))
model.add(tf.keras.layers.Dense(128, activation = 'relu'))
model.add(tf.keras.layers.Dense(10, activation='softmax'))
model.summary()

model.compile(optimizer=optimizers.SGD(learning_rate=0.1),
          loss='sparse_categorical_crossentropy', 
          metrics=['accuracy'])
history = model.fit(x_train, y_train, epochs=18, verbose=2, validation_split=0.2)
test_loss, test_acc = model.evaluate(x_test, y_test)
print('\ntest accuracy:', test_acc)
print('test loss:', test_loss)

predictions = model.predict(x_test)
print((np.argmax(predictions[0])))
print(y_test[0])
