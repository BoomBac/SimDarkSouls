// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template<class T>
class SIMDARKSOULS_API Singleton
{
public:
 static TSharedPtr<T> Get();
 static void Initialize();
private:

 static TSharedPtr<T> Create();

 static TSharedPtr<T> TInstance;
};
template<class T>
TSharedPtr<T> Singleton<T>::TInstance = nullptr;

template <class T>
TSharedPtr<T> Singleton<T>::Get()
{
   Initialize();
   return TInstance;
}

template <class T>
void Singleton<T>::Initialize()
{
 if(!TInstance.IsValid())
   TInstance = Create();
}

template <class T>
TSharedPtr<T> Singleton<T>::Create()
{
  TSharedRef<T> Ref = MakeShareable(new T());
  return Ref;
}
