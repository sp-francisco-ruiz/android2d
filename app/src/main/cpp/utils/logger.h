//
// Created by fjruiz.
//
#ifndef LOGGER_H
#define LOGGER_H

#include <android/log.h>

#define LOG_INFO(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), __VA_ARGS__)
#define LOG_ERROR(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG.c_str(), __VA_ARGS__)


#endif // LOGGER_H