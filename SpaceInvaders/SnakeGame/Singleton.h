#pragma once
template <typename T>
class Singleton {
public:	
	static T& Instance()
	{
		if(Singleton::m_instance == nullptr)
		{
			Singleton::m_instance = CreateInstance();
		}
		return *(Singleton::m_instance);
	}

protected:
	virtual ~Singleton()
	{
		delete Singleton::m_instance;

		Singleton::m_instance = 0;
	}
	
	inline explicit Singleton()
	{
		Singleton::m_instance = static_cast<T*>(this);
	}

private:
	static T* m_instance;
	static T* CreateInstance()
	{
		return new T();
	}
};

template<typename T>
T* Singleton<T>::m_instance = 0;