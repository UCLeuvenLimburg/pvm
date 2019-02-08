// Correct try-finally construct
Exception exception = null;
Resource res = new Resource();
try {
    // Do stuff
}
catch ( Exception e ) {
    exception = e;
    throw e;
}
finally {
    if ( exception != null )
        try {
            res.close();
        }
        catch ( Throwable t ) {
            exception.addSuppressed(t);
        }
    else
        res.close();
}
