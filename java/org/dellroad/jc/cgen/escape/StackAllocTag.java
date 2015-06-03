
//
// @COPYRIGHT@
//
// $Id: StackAllocTag.java,v 1.3 2005/02/20 21:14:31 archiecobbs Exp $
//

package org.dellroad.jc.cgen.escape;

import soot.tagkit.Tag;

/**
 * Tag for stack-allocatable allocations.
 */
public class StackAllocTag implements Tag {

	private final static String NAME = "StackAllocTag";

	int id;

	public StackAllocTag(int id) {
		this.id = id;
	}

	public int getId() {
		return id;
	}

	public byte[] getValue() {
		return new byte[] {
		    (byte)(id >> 24), (byte)(id >> 16),
		    (byte)(id >> 8), (byte)id
		};
	}

	public String getName() {
		return NAME;
	}

	public String toString() {
		return NAME;
	}
}

