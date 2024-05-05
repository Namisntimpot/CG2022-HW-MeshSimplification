#pragma once

#include "../config.h"

namespace Ubpa {
	template<class T> inline T constexpr operator~ (T& a) { return (T)~(GLenum)a; }
	template<class T> inline T constexpr operator& (const T& a, const T& b) { return (T)((GLenum)a & (GLenum)b); }
	template<class T> inline T constexpr operator| (const T& a, const T& b) { return (T)((GLenum)a | (GLenum)b); }
	template<class T> inline T constexpr operator^ (const T& a, const T& b) { return (T)((GLenum)a ^ (GLenum)b); }
	template<class T> inline T& operator|= (T& a, const  T& b) { return (T&)((GLenum&)a |= (GLenum)b); }
	template<class T> inline T& operator&= (T& a, const  T b) { return (T&)((GLenum&)a &= (GLenum)b); }
	template<class T> inline T& operator^= (T& a, const  T b) { return (T&)((GLenum&)a ^= (GLenum)b); }
}
