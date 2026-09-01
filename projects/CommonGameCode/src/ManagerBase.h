//
// Created by esrever2357 on 05/06/2026.
//

#ifndef F28GE_MANAGERBASE_H
#define F28GE_MANAGERBASE_H

namespace cgc
{
    class ManagerBase
    {
    public:
        virtual ~ManagerBase() = default;
        virtual void Initialise(){}
        virtual void Update(float zDeltaTime){}
    };
}

#endif //F28GE_MANAGERBASE_H
