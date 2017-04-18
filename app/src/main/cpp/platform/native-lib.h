//
// Created by fjruiz on 14/04/2017.
//
#ifndef NATIVELIB_H
#define NATIVELIB_H

#include <jni.h>

extern "C"
{
JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnStart(JNIEnv* jenv, jobject obj);
JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnResume(JNIEnv* jenv, jobject obj);
JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnPause(JNIEnv* jenv, jobject obj);
JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnStop(JNIEnv* jenv, jobject obj);
JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnPress(JNIEnv* jenv, jobject obj);
JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetSurface(JNIEnv* jenv, jobject obj, jobject surface);
JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetAssetManager(JNIEnv* jenv, jobject obj, jobject manager);
};

#endif // NATIVELIB_H