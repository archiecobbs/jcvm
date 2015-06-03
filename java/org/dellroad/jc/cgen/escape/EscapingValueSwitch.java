
//
// @COPYRIGHT@
//
// $Id: EscapingValueSwitch.java,v 1.1 2004/11/27 23:11:04 archiecobbs Exp $
//

package org.dellroad.jc.cgen.escape;

import java.util.*;
import org.dellroad.jc.cgen.*;
import soot.*;
import soot.jimple.*;

/**
 * Checks for values where the local can escape. The result
 * is <code>Boolean.TRUE</code> if so, <code>Boolean.FALSE</code> if not,
 * or <code>null</code> if the local can only escape as the 'return value'
 * of the <code>Value</code> itself.
 */
public class EscapingValueSwitch extends AbstractJimpleValueSwitch {

	private Local local;

	public Local getLocal() {
		return local;
	}

	public void setLocal(Local local) {
		this.local = local;
	}

	public void caseCastExpr(CastExpr v) {
		v.getOp().apply(this);
	}

	public void caseLocal(Local v) {
		setResult(v.equals(local) ? null : Boolean.FALSE);
	}

	public void caseInterfaceInvokeExpr(InterfaceInvokeExpr expr) {
		caseInstanceInvokeExpr(expr);
	}

	public void caseSpecialInvokeExpr(SpecialInvokeExpr expr) {
		caseInstanceInvokeExpr(expr);
	}

	public void caseVirtualInvokeExpr(VirtualInvokeExpr expr) {
		caseInstanceInvokeExpr(expr);
	}

	public void caseStaticInvokeExpr(StaticInvokeExpr expr) {
		handleInvokeParameters(expr);
	}

	private void caseInstanceInvokeExpr(InstanceInvokeExpr expr) {
		expr.getBase().apply(this);
		if (getResult() != Boolean.FALSE) {
			setResult(Boolean.TRUE);
			return;
		}
		handleInvokeParameters(expr);
	}

	private void handleInvokeParameters(InvokeExpr expr) {
		int argCount = expr.getArgCount();
		for (int i = 0; i < argCount; i++) {
			expr.getArg(i).apply(this);
			if (getResult() != Boolean.FALSE) {
				setResult(Boolean.TRUE);
				return;
			}
		}
		setResult(Boolean.FALSE);
	}

	public void defaultCase(Object obj) {
		setResult(Boolean.FALSE);
	}
}

