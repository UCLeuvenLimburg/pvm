import React from 'react';
import { createRoot } from 'react-dom/client';
import CssBaseline from '@mui/material/CssBaseline';
import { Test } from '@shared/test';


function App() {
  return (
    <div>
      <h1>Hello, world!</h1>
      <Test />
    </div>
  );
}


const rootContainer = document.getElementById('root');

if ( rootContainer ) {
    const root = createRoot(rootContainer);
    
    root.render(
        <>
            <CssBaseline />
            <App />
        </>
    );
}
else
{
    throw Error("Could not find root container");
}
