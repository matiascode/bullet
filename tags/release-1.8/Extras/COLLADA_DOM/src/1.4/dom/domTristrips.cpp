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
#include <dom/domTristrips.h>

daeElementRef
domTristrips::create(daeInt bytes)
{
	domTristripsRef ref = new(bytes) domTristrips;
	return ref;
}


daeMetaElement *
domTristrips::registerElement()
{
    if ( _Meta != NULL ) return _Meta;
    
    _Meta = new daeMetaElement;
    _Meta->setName( "tristrips" );
	_Meta->setStaticPointerAddress(&domTristrips::_Meta);
	_Meta->registerConstructor(domTristrips::create);

	// Add elements: input, p, extra
    _Meta->appendArrayElement(domInputLocalOffset::registerElement(),daeOffsetOf(domTristrips,elemInput_array),"input"); 
    _Meta->appendArrayElement(domP::registerElement(),daeOffsetOf(domTristrips,elemP_array));
    _Meta->appendArrayElement(domExtra::registerElement(),daeOffsetOf(domTristrips,elemExtra_array));

	//	Add attribute: name
 	{
		daeMetaAttribute *ma = new daeMetaAttribute;
		ma->setName( "name" );
		ma->setType( daeAtomicType::get("xsNCName"));
		ma->setOffset( daeOffsetOf( domTristrips , attrName ));
		ma->setContainer( _Meta );
	
		_Meta->appendAttribute(ma);
	}

	//	Add attribute: count
 	{
		daeMetaAttribute *ma = new daeMetaAttribute;
		ma->setName( "count" );
		ma->setType( daeAtomicType::get("Uint"));
		ma->setOffset( daeOffsetOf( domTristrips , attrCount ));
		ma->setContainer( _Meta );
		ma->setIsRequired( true );
	
		_Meta->appendAttribute(ma);
	}

	//	Add attribute: material
 	{
		daeMetaAttribute *ma = new daeMetaAttribute;
		ma->setName( "material" );
		ma->setType( daeAtomicType::get("xsNCName"));
		ma->setOffset( daeOffsetOf( domTristrips , attrMaterial ));
		ma->setContainer( _Meta );
	
		_Meta->appendAttribute(ma);
	}
	
	
	_Meta->setElementSize(sizeof(domTristrips));
	_Meta->validate();

	return _Meta;
}


daeMetaElement * domTristrips::_Meta = NULL;


