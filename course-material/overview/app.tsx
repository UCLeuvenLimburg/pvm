import * as React from 'react';
import { Overview } from './overview';
import styled from 'styled-components';


const Header = styled.h1`
  text-align: center;
  background: black;
  color: white;
  margin: 0;
  padding: 1em;
`;

export class App extends React.Component<{}, {}>
{
  render()
  {
    return (
      <React.Fragment>
        <Header>PVM</Header>
        <Overview />
      </React.Fragment>
    );
  }
}
