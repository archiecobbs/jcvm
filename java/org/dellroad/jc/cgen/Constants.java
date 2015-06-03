
//
// @COPYRIGHT@
//
// $Id: Constants.java,v 1.1.1.1 2004/02/20 05:15:25 archiecobbs Exp $
//

package org.dellroad.jc.cgen;

/**
 * Constants that define the sizes of certain automatically
 * generated hash tables used by generated C code.
 */
public interface Constants {
	/**
	 * Size of interface method lookup hash tables
	 * and ``quick'' interface method lookup tables.
	 * Must be a power of two and equal to the definition
	 * in <code>jc_defs.h</code>.
	 */
	public static final int IMETHOD_HASHSIZE = 128;

	/**
	 * Size of instanceof hash tables.
	 * Must be a power of two and equal to the definition
	 * in <code>jc_defs.h</code>.
	 */
	public static final int INSTANCEOF_HASHSIZE = 128;
}

