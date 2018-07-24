#ifndef COLLISIONPDU_H
#define COLLISIONPDU_H

#include <dis7/EntityID.h>
#include <dis7/EntityID.h>
#include <dis7/EventIdentifier.h>
#include <dis7/Vector3Float.h>
#include <dis7/Vector3Float.h>
#include <dis7/EntityInformationFamilyPdu.h>
#include <utils/DataStream.h>
#include <dis7/msLibMacro.h>


namespace DIS
{
// Section 7.2.3 Collisions between entities shall be communicated by issuing a Collision PDU. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO CollisionPdu : public EntityInformationFamilyPdu
{
protected:
  /** This field shall identify the entity that is issuing the PDU, and shall be represented by an Entity Identifier record (see 6.2.28). */
  EntityID _issuingEntityID; 

  /** This field shall identify the entity that has collided with the issuing entity (see 5.3.3.4). This field shall be represented by an Entity Identifier record (see 6.2.28). */
  EntityID _collidingEntityID; 

  /** This field shall contain an identification generated by the issuing simulation application to associate related collision events. This field shall be represented by an Event Identifier record (see 6.2.34). */
  EventIdentifier _eventID; 

  /** This field shall identify the type of collision. The Collision Type field shall be represented by an 8-bit record of enumerations */
  unsigned char _collisionType; 

  /** some padding */
  char _pad; 

  /** This field shall contain the velocity (at the time the collision is detected) of the issuing entity. The velocity shall be represented in world coordinates. This field shall be represented by the Linear Velocity Vector record [see 6.2.95 item c)]. */
  Vector3Float _velocity; 

  /** This field shall contain the mass of the issuing entity, and shall be represented by a 32-bit floating point number representing kilograms. */
  float _mass; 

  /** This field shall specify the location of the collision with respect to the entity with which the issuing entity collided. The Location field shall be represented by an Entity Coordinate Vector record [see 6.2.95 item a)]. */
  Vector3Float _location; 


 public:
    CollisionPdu();
    virtual ~CollisionPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityID& getIssuingEntityID(); 
    const EntityID&  getIssuingEntityID() const; 
    void setIssuingEntityID(const EntityID    &pX);

    EntityID& getCollidingEntityID(); 
    const EntityID&  getCollidingEntityID() const; 
    void setCollidingEntityID(const EntityID    &pX);

    EventIdentifier& getEventID(); 
    const EventIdentifier&  getEventID() const; 
    void setEventID(const EventIdentifier    &pX);

    unsigned char getCollisionType() const; 
    void setCollisionType(unsigned char pX); 

    char getPad() const; 
    void setPad(char pX); 

    Vector3Float& getVelocity(); 
    const Vector3Float&  getVelocity() const; 
    void setVelocity(const Vector3Float    &pX);

    float getMass() const; 
    void setMass(float pX); 

    Vector3Float& getLocation(); 
    const Vector3Float&  getLocation() const; 
    void setLocation(const Vector3Float    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const CollisionPdu& rhs) const;
};
}

#endif
// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
