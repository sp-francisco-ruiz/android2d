//
// Created by fjruiz.
//
#include <jni.h>

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <string>

#include "native-lib.h"
#include "utils/logger.h"
#include "platform/application.h"

const std::string LOG_TAG("JNI");

static platform::Application *mainApp = nullptr;

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnStart(JNIEnv* jenv, jobject obj)
{
    mainApp = new platform::Application();
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnResume(JNIEnv* jenv, jobject obj)
{
    mainApp->Start();
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnPause(JNIEnv* jenv, jobject obj)
{
    mainApp->Stop();
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnStop(JNIEnv* jenv, jobject obj)
{
    delete mainApp;
    mainApp = nullptr;
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnPress(JNIEnv* jenv, jobject obj)
{
    mainApp->OnPressed();
}
JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetSurface(JNIEnv* jenv, jobject obj, jobject surface);

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetSurface(JNIEnv* jenv, jobject obj, jobject surface)
{
    if (surface != 0)
    {
        ANativeWindow *window = ANativeWindow_fromSurface(jenv, surface);
        mainApp->SetWindow(window);
    }
    else
    {
        mainApp->SetWindow(nullptr);
    }

    return;
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetAssetManager(JNIEnv* jenv, jobject obj, jobject manager)
{
    auto assets = AAssetManager_fromJava(jenv, manager);
    mainApp->SetAssets(assets);
}