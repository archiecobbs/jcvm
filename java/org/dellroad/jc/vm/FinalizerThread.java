
//
// @COPYRIGHT@
//
// $Id: FinalizerThread.java,v 1.1.1.1 2004/02/20 05:15:26 archiecobbs Exp $
//

package org.dellroad.jc.vm;

/**
 * JC finalizer thread.
 */
class FinalizerThread extends Thread {

	FinalizerThread() {
		super("finalizer");
		setPriority(MIN_PRIORITY);
	}

	public void run() {
		while (true) {
			waitForInterrupt();
			finalizeObjects();
		}
	}

	// VM will call Thread.interrupt() after each GC cycle
	synchronized void waitForInterrupt() {
		try {
			wait();
		} catch (InterruptedException e) {
		}
	}

	static native void finalizeObjects();
}

