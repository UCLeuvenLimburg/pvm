import React from 'react';
import { createRoot } from 'react-dom/client';


const rootContainer = document.getElementById('root');

if ( rootContainer ) {
    const root = createRoot(rootContainer);
    root.render(<h1>Hello, world!</h1>);
}
else
{
    throw Error("Could not find root container");
}
