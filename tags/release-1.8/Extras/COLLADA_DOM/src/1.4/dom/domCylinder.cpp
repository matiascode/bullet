/*
 * Copyright 2006 Sony Computer Entertainment Inc.
 *
 * Licensed under the SCEA Shared Source License, Version 1.0 (the "License"); you may not use this 
 * file except in compliance with the License. You may obtain a copy of the License at:
 * http://research.scea.com/scea_shared_source_license.html
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License 
 * is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
 * implied. See the License for the specific language governing permissions and limitations under the 
 * License. 
 */

#include <dae/daeDom.h>
#include <dom/domCylinder.h>

daeElementRef
domCylinder::create(daeInt bytes)
{
	domCylinderRef ref = new(bytes) domCylinder;
	return ref;
}


daeMetaElement *
domCylinder::registerElement()
{
    if ( _Meta != NULL ) return _Meta;
    
    _Meta = new daeMetaElement;
    _Meta->setName( "cylinder" );
	_Meta->setStaticPointerAddress(&domCylinder::_Meta);
	_Meta->registerConstructor(domCylinder::create);

	// Add elements: height, radius, extra
    _Meta->appendElement(domCylinder::domHeight::registerElement(),daeOffsetOf(domCylinder,elemHeight));
    _Meta->appendElement(domCylinder::domRadius::registerElement(),daeOffsetOf(domCylinder,elemRadius));
    _Meta->appendArrayElement(domExtra::registerElement(),daeOffsetOf(domCylinder,elemExtra_array));
	
	
	_Meta->setElementSize(sizeof(domCylinder));
	_Meta->validate();

	return _Meta;
}

daeElementRef
domCylinder::domHeight::create(daeInt bytes)
{
	domCylinder::domHeightRef ref = new(bytes) domCylinder::domHeight;
	return ref;
}


daeMetaElement *
domCylinder::domHeight::registerElement()
{
    if ( _Meta != NULL ) return _Meta;
    
    _Meta = new daeMetaElement;
    _Meta->setName( "height" );
	_Meta->setStaticPointerAddress(&domCylinder::domHeight::_Meta);
	_Meta->registerConstructor(domCylinder::domHeight::create);

	//	Add attribute: _value
 	{
		daeMetaAttribute *ma = new daeMetaAttribute;
		ma->setName( "_value" );
		ma->setType( daeAtomicType::get("Float"));
		ma->setOffset( daeOffsetOf( domCylinder::domHeight , _value ));
		ma->setContainer( _Meta );
		_Meta->appendAttribute(ma);
	}
	
	
	_Meta->setElementSize(sizeof(domCylinder::domHeight));
	_Meta->validate();

	return _Meta;
}

daeElementRef
domCylinder::domRadius::create(daeInt bytes)
{
	domCylinder::domRadiusRef ref = new(bytes) domCylinder::domRadius;
	return ref;
}


daeMetaElement *
domCylinder::domRadius::registerElement()
{
    if ( _Meta != NULL ) return _Meta;
    
    _Meta = new daeMetaElement;
    _Meta->setName( "radius" );
	_Meta->setStaticPointerAddress(&domCylinder::domRadius::_Meta);
	_Meta->registerConstructor(domCylinder::domRadius::create);

	//	Add attribute: _value
 	{
		daeMetaAttribute *ma = new daeMetaArrayAttribute;
		ma->setName( "_value" );
		ma->setType( daeAtomicType::get("Float2"));
		ma->setOffset( daeOffsetOf( domCylinder::domRadius , _value ));
		ma->setContainer( _Meta );
		_Meta->appendAttribute(ma);
	}
	
	
	_Meta->setElementSize(sizeof(domCylinder::domRadius));
	_Meta->validate();

	return _Meta;
}


daeMetaElement * domCylinder::_Meta = NULL;
daeMetaElement * domCylinder::domHeight::_Meta = NULL;
daeMetaElement * domCylinder::domRadius::_Meta = NULL;


